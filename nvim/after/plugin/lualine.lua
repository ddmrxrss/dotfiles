require('lualine').setup {
    options = {
        theme = 'auto',
        component_separators = { left = '', right = ''},
        section_separators = { left = '', right = ''},
    },
    sections = {
        lualine_b = {'branch'},
        lualine_x = {'filetype'},
        lualine_y = {},
    }
}
