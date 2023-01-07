require('lualine').setup {
    options = {
        theme = 'palenight',
        section_separators = '',
        component_separators = ''
    },
    sections = {
        lualine_b = {'branch', 'diagnostics'},
        lualine_x = {},
        lualine_y = {},
    
    }
}
